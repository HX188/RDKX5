Page({
  data: {
    client: null,
    host: "w16e190a.ala.cn-hangzhou.emqxsl.cn",
    subTopic: "/wechat_ros_return/mqtt",
    pubTopic: "/wechat_ros/mqtt",
    pubMsg: "Hello! Nice to meet you!",
    receivedMsg: "",
    scrollToView: '',
    isSubscribed: false,
  },

  messageListenerRegistered: false,

  onLoad() {
    const app = getApp();

    const setupClient = (client) => {
      this.setData({ client });

      client.subscribe(this.data.subTopic, (err) => {
        if (!err) {
          console.log("自动订阅成功：", this.data.subTopic);
        } else {
          console.error("订阅失败：", err);
        }
      });

      if (!this.messageListenerRegistered) {
        client.on("message", (topic, payload) => {
          console.log("收到消息：", topic, payload.toString());
          const currMsg = this.data.receivedMsg ? `<br/>${payload}` : payload;
          this.setData({
            receivedMsg: this.data.receivedMsg + currMsg,
            scrollToView: 'msg-end'
          });
        });
        this.messageListenerRegistered = true;
      }

      wx.showToast({ title: '已连接 MQTT' });
    };

    if (app.globalData.client && app.globalData.client.connected) {
      setupClient(app.globalData.client);
    } else {
      app.globalData.mqttReadyCallbacks.push(setupClient);
    }
  },

  setValue(key, value) {
    this.setData({ [key]: value });
  },
  setSubTopic(e) {
    this.setValue("subTopic", e.detail.value);
  },
  setPubTopic(e) {
    this.setValue("pubTopic", e.detail.value);
  },
  setPubMsg(e) {
    this.setValue("pubMsg", e.detail.value);
  },

  subscribe() {
    if (this.data.client) {
      this.data.client.subscribe(this.data.subTopic, (err) => {
        if (!err) {
          this.setData({ isSubscribed: true });
          wx.showModal({
            content: `成功订阅：${this.data.subTopic}`,
            showCancel: false,
          });
        } else {
          wx.showToast({ title: "订阅失败", icon: "error" });
        }
      });
    } else {
      wx.showToast({ title: "未连接", icon: "error" });
    }
  },
  
  unsubscribe() {
    if (this.data.client) {
      this.data.client.unsubscribe(this.data.subTopic);
      this.setData({ isSubscribed: false }); 
      wx.showModal({
        content: `取消订阅：${this.data.subTopic}`,
        showCancel: false,
      });
    } else {
      wx.showToast({ title: "未连接", icon: "error" });
    }
  },  

  publish() {
    if (this.data.client) {
      this.data.client.publish(this.data.pubTopic, this.data.pubMsg);
    } else {
      wx.showToast({
        title: "未连接",
        icon: "error"
      });
    }
  },

  goToControl() {
    wx.navigateTo({
      url: '/pages/control/control',
    });
  },

  clearReceivedMsg() {
    this.setData({ receivedMsg: "" });
  },

  clearRetainedMsg() {
    if (this.data.client) {
      this.data.client.publish(this.data.subTopic, '', { retain: true });
      wx.showToast({ title: '已发送空消息' });
    }
  }
});
