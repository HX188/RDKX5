const mqtt = require('./utils/mqtt.min.js');

App({
  globalData: {
    client: null,
    mqttReadyCallbacks: []  // 等待MQTT连接
  },

  onLaunch() {
    const client = mqtt.connect('wxs://w16e190a.ala.cn-hangzhou.emqxsl.cn:8084/mqtt', {
      username: 'test',
      password: 'test',
      clientId: 'wechat_client_' + Date.now() + '_' + Math.floor(Math.random() * 1000),
      reconnectPeriod: 1000,
      connectTimeout: 30 * 1000
    });

    this.globalData.client = client;

    client.on('connect', () => {
      console.log('MQTT connected');

      this.globalData.mqttReadyCallbacks.forEach(cb => cb(client));
      this.globalData.mqttReadyCallbacks = [];

      client.subscribe('/wechat_ros/mqtt');
    });

    client.on('error', (err) => {
      console.error('MQTT error:', err);
    });

    client.on('message', (topic, message) => {
      console.log('全局消息:', topic, message.toString());
    });
  }
});
