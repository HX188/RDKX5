Page({
  data: {
    handleX: 0,
    handleY: 0,
    sliderX: 0,
    speedvalue: 0,
    rotatevalue: 0,
    crossValue: 0,
  },

  joystickTouchId: null,
  sliderTouchId: null,
  lastSendTime: 0,

  sendCommand(x, y, cross) {
    const now = Date.now();
    const throttleInterval = 150;
    if (now - this.lastSendTime < throttleInterval) return;
    this.lastSendTime = now;

    const client = getApp().globalData.client;
    if (client && client.connected) {
      const msg = `speed=${Number(y).toFixed(2)},rotate=${Number(x).toFixed(2)},cross=${Number(cross).toFixed(2)}`;
      client.publish('/wechat_ros/mqtt', msg, {
        qos: 0,
        retain: false
      });
    }
  },

  onMultiTouchStart(e) {
    const rpxPerPx = 750 / wx.getSystemInfoSync().windowWidth;
    const query = wx.createSelectorQuery();
    query.select('.joystick').boundingClientRect();
    query.select('.slider-container').boundingClientRect();

    query.exec(rects => {
      const joystickRect = rects[0];
      const sliderRect = rects[1];

      e.touches.forEach(touch => {
        const { identifier, clientX, clientY } = touch;

        if (
          this.joystickTouchId === null &&
          clientX >= joystickRect.left &&
          clientX <= joystickRect.right &&
          clientY >= joystickRect.top &&
          clientY <= joystickRect.bottom
        ) {
          this.joystickTouchId = identifier;
          this.updateHandlePositionFromTouch(touch, joystickRect, rpxPerPx);
        } else if (
          this.sliderTouchId === null &&
          clientX >= sliderRect.left &&
          clientX <= sliderRect.right &&
          clientY >= sliderRect.top &&
          clientY <= sliderRect.bottom
        ) {
          this.sliderTouchId = identifier;
          this.updateSliderPositionFromTouch(touch, sliderRect, rpxPerPx);
        }
      });
    });
  },

  onMultiTouchMove(e) {
    const rpxPerPx = 750 / wx.getSystemInfoSync().windowWidth;
    const query = wx.createSelectorQuery();
    query.select('.joystick').boundingClientRect();
    query.select('.slider-container').boundingClientRect();

    query.exec(rects => {
      const joystickRect = rects[0];
      const sliderRect = rects[1];

      e.touches.forEach(touch => {
        const { identifier } = touch;
        if (identifier === this.joystickTouchId) {
          this.updateHandlePositionFromTouch(touch, joystickRect, rpxPerPx);
        } else if (identifier === this.sliderTouchId) {
          this.updateSliderPositionFromTouch(touch, sliderRect, rpxPerPx);
        }
      });
    });
  },

  onMultiTouchEnd(e) {
    e.changedTouches.forEach(touch => {
      const { identifier } = touch;

      if (identifier === this.joystickTouchId) {
        this.setData({
          handleX: 0,
          handleY: 0,
          speedvalue: 0,
          rotatevalue: 0
        });
        this.joystickTouchId = null;
      }

      if (identifier === this.sliderTouchId) {
        this.setData({
          sliderX: 0,
          crossValue: 0
        });
        this.sliderTouchId = null;
      }

      setTimeout(() => {
        const client = getApp().globalData.client;
        if (client && client.connected) {
          const msg = `speed=0.00,rotate=0.00,cross=0.00`;
          client.publish('/wechat_ros/mqtt', msg, {
            qos: 0,
            retain: false
          });
        }
      }, 50);
    });
  },

  updateHandlePositionFromTouch(touch, rect, rpxPerPx) {
    const centerX = rect.width / 2;
    const centerY = rect.height / 2;

    const x = touch.clientX - rect.left - centerX;
    const y = touch.clientY - rect.top - centerY;

    const maxRadius = centerX;
    const distance = Math.sqrt(x * x + y * y);

    let newX = x;
    let newY = y;
    if (distance > maxRadius) {
      const ratio = maxRadius / distance;
      newX = x * ratio;
      newY = y * ratio;
    }

    this.setData({
      handleX: newX * rpxPerPx,
      handleY: newY * rpxPerPx,
    });

    if (newY < 0) newX = -newX;

    const normX = newX / maxRadius * 0.3;
    const normY = -newY / maxRadius * 0.5;

    this.setData({
      speedvalue: normY,
      rotatevalue: normX
    });

    this.sendCommand(normX.toFixed(2), normY.toFixed(2), this.data.crossValue);
  },

  updateSliderPositionFromTouch(touch, rect, rpxPerPx) {
    const containerLeft = rect.left;
    const containerWidth = rect.width;
    const centerX = containerWidth / 2;

    let deltaX = touch.clientX - containerLeft - centerX;
    const maxOffset = centerX;
    deltaX = Math.max(-maxOffset, Math.min(deltaX, maxOffset));

    const norm = deltaX / maxOffset * 0.5;
    const cross = parseFloat(norm.toFixed(2));

    this.setData({
      sliderX: deltaX * rpxPerPx,
      crossValue: cross,
    });

    this.sendCommand(this.data.speedvalue,
      this.data.rotatevalue, cross);
  }
});
