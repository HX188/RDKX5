# Wechat_miniAPP
* The subfolder version1.0.0 under this directory contains the development code for the WeChat mini-program.
* Development platform: WeChat Developer Tool.

# Wechat_miniAPP/version1.0.0
* The files project.config.json and project.private.config.json in this directory contain basic configurations for the mini-program project.
* project.config.json declares the appid, which is a critical object in WeChat mini-program development. To develop the project, the appid must correspond to the APPID of your own account.
* project.private.config.json serves a similar purpose as the previous file, but the content in this file will override the corresponding fields in project.config.json. Any changes to the project should be synchronized with this file.
* For more details, refer to the official documentation provided by WeChat Public Platform: https://developers.weixin.qq.com/miniprogram/dev/devtools/projectconfig.html
* The files app.js, app.json, and app.wxss in this directory handle some initialization tasks for the mini-program.
* app.js creates a client based on the MQTT service.
* It is important to note that the domain name used when connecting to the MQTT service is the EMQX server applied for by the developer. The username and password used for the connection are the corresponding users authorized in the server by the developer. The EMQX server must grant access with the specified domain and user, and the domain of the EMQX server (socket type) should also be added to the developer account of the WeChat mini-program.

# Wechat_miniAPP/version1.0.0/pages
* This directory contains design code for three interfaces: the main page, remote control interface, and log interface.
* index: Main page, which includes: input text areas and buttons; an information display area with a scrolling effect to show subscribed RDK end information; a navigation button to jump to the remote control interface.
* control: Remote control interface, which includes: a slider to generate one degree of freedom (DOF) information; a joystick to generate two degrees of freedom (DOF) information; together, they generate a three-DOF remote control information set. Since WeChat mini-programs do not support independent binding between fingers and components in multi-touch, a multi-touch detection strategy is designed for dual-finger touch and independent binding, enabling the simultaneous touch of multiple components.
* log: Log interface, mainly for printing important log information during the mini-program's operation. Only users with developer privileges can view this interface.
