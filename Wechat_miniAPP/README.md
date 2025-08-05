# Wechat_miniAPP
* 本目录下的子文件夹version1.0.0即为微信小程序端的开发代码。
* 开发平台：微信开发者工具。

# Wechat_miniAPP/version1.0.0
* 此目录下的 project.config.json、project.private.config.json 进行了一些小程序项目上最基础的配置。
* 其中 project.config.json 声明了appid，这是微信小程序开发中很重要的一个对象，若要对项目进行开发，必须使appid为自己账号所对应的APPID。
* 其中 project.private.config.json 作用与前者相似，不过此文件中的内容将覆盖 project.config.json 中的相同字段，项目的改动优先同步到此文件中。
* 详见微信公众平台提供的官方文档：https://developers.weixin.qq.com/miniprogram/dev/devtools/projectconfig.html"
* 此目录下的 app.js、app.json、app.wxss 进行了小程序的一些初始化相关操作。
* 其中 app.js 创建了一个基于MQTT服务的客户端。
* 需要注意的是，MQTT服务连接时所使用的域名，为开发者自己申请的EMQX服务器；连接时所使用的用户名和密码，也是开发者自己在服务器中明确授权的对应用户；若使用该域名和用户名，需要EMQX服务器中开放授权，且需要在自己的微信小程序开发者账号中添加该EMQX服务器的域名（socket类型）。

# Wechat_miniAPP/version1.0.0/pages
* 此目录下包含三个界面的设计代码：主页面、遥控界面、日志界面。
* index：主界面，包括：一些可输入的文本区域和按钮；一个信息显示区域，并设计了滚屏显示效果，用于显示订阅到的RDK端信息；一个跳转按钮，用于跳转到遥控界面。
* control：遥控界面，包括：一个滑杆，用于产生一自由度信息；一个摇杆，用于产生二自由度信息；二者联合产生了三自由度的遥控信息组。由于微信小程序不支持多指触控时手指与组件之间的独立绑定，因此设计了多指检测策略，用于双指触控和独立绑定，实现了多组件同时触控功能。
* log：日志界面，主要打印一些小程序运行过程中的重要日志信息，仅具有开发者权限的用户可以查看该界面。
