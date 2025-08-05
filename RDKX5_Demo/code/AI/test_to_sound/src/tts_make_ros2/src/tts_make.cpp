#include "wav_head.h"
#include "tts_make.h"

using namespace std;
std::string AUDIO_PATH = "/home/sunrise/AI/test_to_sound/src/tts_make_ros2/audio";
std::string WHOLE;
std::string head = "aplay ";


wstring TTS::s2ws(const std::string &str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

string TTS::ws2s(const std::wstring &wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

/* 获取时间 */
string TTS::current_time()
{
	std::string fmt = ".wav";
    static char t_buf[64];
	time_t now_time = time(NULL);
    struct tm* time = localtime(&now_time);
    strftime(t_buf, 64, "%Y-%m-%d_%H:%M:%S", time);
    std::wstring wtxt = s2ws(t_buf);
	std::string txt_uft8 = ws2s(wtxt);
    txt_uft8 += fmt;
    return txt_uft8;
}

/* 文本合成 */
int TTS::text_to_speech(const char* src_text, const char* des_path, const char* params)
{
	int          ret          = -1;
	FILE*        fp           = NULL;
	const char*  sessionID    = NULL;
	unsigned int audio_len    = 0;
	wave_pcm_hdr wav_hdr      = default_wav_hdr;
	int          synth_status = MSP_TTS_FLAG_STILL_HAVE_DATA;
	sessionID=NULL;

	if (NULL == src_text || NULL == des_path)
	{
		printf("params is error!\n");
		return ret;
	}
	fp = fopen(des_path, "wb");
	if (NULL == fp)
	{
		printf("open %s error.\n", des_path);
		return ret;
	}
	/* 开始合成 */
	sessionID = QTTSSessionBegin(params, &ret);
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSSessionBegin failed, error code: %d.\n", ret);
		fclose(fp);
		return ret;
	}
	ret = QTTSTextPut(sessionID, src_text, (unsigned int)strlen(src_text), NULL);
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSTextPut failed, error code: %d.\n",ret);
		QTTSSessionEnd(sessionID, "TextPutError");
		fclose(fp);
		return ret;
	}
	printf("正在合成 ...\n");
	fwrite(&wav_hdr, sizeof(wav_hdr) ,1, fp); //添加wav音频头，使用采样率为16000
	while (1) 
	{
		/* 获取合成音频 */
		const void* data = QTTSAudioGet(sessionID, &audio_len, &synth_status, &ret);
		if (MSP_SUCCESS != ret)
			break;
		if (NULL != data)
		{
			fwrite(data, audio_len, 1, fp);
		    wav_hdr.data_size += audio_len; //计算data_size大小
		}
		if (MSP_TTS_FLAG_DATA_END == synth_status )
			break;
		
		
	}
	printf("\n");
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSAudioGet failed, error code: %d.\n",ret);
		QTTSSessionEnd(sessionID, "AudioGetError");
		fclose(fp);
		return ret;
	}
	/* 修正wav文件头数据的大小 */
	wav_hdr.size_8 += wav_hdr.data_size + (sizeof(wav_hdr) - 8);
	
	/* 将修正过的数据写回文件头部,音频文件为wav格式 */
	fseek(fp, 4, 0);
	fwrite(&wav_hdr.size_8,sizeof(wav_hdr.size_8), 1, fp); //写入size_8的值
	fseek(fp, 40, 0); //将文件指针偏移到存储data_size值的位置
	fwrite(&wav_hdr.data_size,sizeof(wav_hdr.data_size), 1, fp); //写入data_size的值
	fclose(fp);
	fp = NULL;
	/* 合成完毕 */
	ret = QTTSSessionEnd(sessionID, "Normal");
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSSessionEnd failed, error code: %d.\n",ret);
	}

	return ret;
}

/* 语音合成 */
int TTS::init()
{

	int         ret                  = MSP_SUCCESS;
	// std::string login_ori		 	 = "appid = ";
	// std::string login_fin     	 	 = login_ori + appid + ", work_dir = .";
	// const char* login_params = login_fin.c_str();//登录参数,appid与msc库绑定,请勿随意改动
	
	

	std::string session_ori_1		 = "engine_type = local,voice_name=";
	std::string session_ori_2		 = ", text_encoding = UTF8, tts_res_path = fo|";
	std::string session_ori_3		 = "/home/sunrise/AI/test_to_sound/install/tts/share/tts/config/bin/msc/res/tts/xiaoyan.jet;fo|";
	std::string session_ori_4		 = "/home/sunrise/AI/test_to_sound/install/tts/share/tts/config/bin/msc/res/tts/common.jet, sample_rate = ";
	std::string session_ori_5	 	 = ", volume = ";
	std::string session_ori_6	 	 = ", pitch = ";
	std::string session_ori_7	 	 = ", rdn = ";
	std::string session_ori_8	 	 = ", speed = ";
	std::string session_fin			 = session_ori_1 + voice_name + session_ori_2  + session_ori_3 + session_ori_4 + std::to_string(sample_rate) + session_ori_5 + std::to_string(volume) + session_ori_6 + std::to_string(pitch) + session_ori_7 + std::to_string(rdn) + session_ori_8 + std::to_string(speed);
	const char* session_begin_params = session_fin.c_str();
	cout<< ">>>>>>> session_begin_params:"<< session_begin_params<< endl;


	

	

	/* 用户登录 */
	// ret = MSPLogin(NULL, NULL, login_params); //第一个参数是用户名，第二个参数是密码，第三个参数是登录参数，用户名和密码可在http://www.xfyun.cn注册获取
	// if (MSP_SUCCESS != ret){
	// 	RCLCPP_INFO(this->get_logger(),"MSPLogin failed, error code: %d.\n", ret);
	// 	MSPLogout(); //退出登录
	// 	return 0;
	// 	//goto exit ;//登录失败，退出登录
	// }

	std::string audio_path = "src/tts_make_ros2/audio/";
	std::string repalce = "install/tts/share/tts";
	size_t start_pos = source_path.find(repalce);
	if(start_pos != std::string::npos) {
        source_path.replace(start_pos, repalce.length(), audio_path);
    }
    //cout<< ">>>>>>> source_path:"<< source_path << endl;
	//std::string filename_fin		 = source_path + current_time();
	std::string filename_fin		 = source_path + "voice_control.wav";
	const char* filename             = filename_fin.c_str(); //合成的语音文件名称
	//cout<< ">>>>>>> filename:"<< filename << endl;
	const char* text                 = tts_text.c_str(); //合成文本
	

	RCLCPP_INFO(this->get_logger(),"\n###########################################################################");
	RCLCPP_INFO(this->get_logger(),"## 语音合成（Text To Speech，TTS）技术能够自动将任意文字实时转换为连续的 ##");
	RCLCPP_INFO(this->get_logger(),"## 自然语音，是一种能够在任何时间、任何地点，向任何人提供语音信息服务的  ##");
	RCLCPP_INFO(this->get_logger(),"## 高效便捷手段，非常符合信息时代海量数据、动态更新和个性化查询的需求。  ##");
	RCLCPP_INFO(this->get_logger(),"###########################################################################\n");

	/* 文本合成 */
	RCLCPP_INFO(this->get_logger(),"开始合成 ...");
	ret = text_to_speech(text, filename, session_begin_params);
	if (MSP_SUCCESS != ret)
	{
		RCLCPP_INFO(this->get_logger(),"text_to_speech failed, error code: %d.", ret);
	}
	RCLCPP_INFO(this->get_logger(),"合成完毕\n");
	WHOLE = head + AUDIO_PATH + "/voice_control.wav";
	system(WHOLE.c_str());
	remove((AUDIO_PATH + "/voice_control.wav").c_str());

	// MSPLogout();
	return 0;

}

/* 初始化 */
TTS::TTS(const std::string &node_name,const rclcpp::NodeOptions &options) 
: rclcpp::Node(node_name,options){
	this->declare_parameter<int>("rdn",0);
	this->declare_parameter<int>("volume",0);
	this->declare_parameter<int>("pitch",0);
	this->declare_parameter<int>("speed",0);
	this->declare_parameter<int>("sample_rate",0);
	this->declare_parameter<string>("source_path","");
	this->declare_parameter<string>("appid","");
	this->declare_parameter<string>("voice_name","");
	this->declare_parameter<string>("tts_text","");

	this->get_parameter("rdn",rdn);
	this->get_parameter("volume",volume);
	this->get_parameter("pitch",pitch);
	this->get_parameter("speed",speed);
	this->get_parameter("sample_rate",sample_rate);
	this->get_parameter<string>("source_path",source_path);
	this->get_parameter<string>("appid",appid);
	this->get_parameter<string>("voice_name",voice_name);
	this->get_parameter<string>("tts_text",tts_text);

	

	RCLCPP_INFO(this->get_logger(),"%s node init!\n",node_name.c_str());

	tts_text_sub = this->create_subscription<std_msgs::msg::String>(
        "tts_text", 10, std::bind(&TTS::tts_text_callback, this, std::placeholders::_1));

	int         ret                  = MSP_SUCCESS;
	std::string login_ori		 	 = "appid = ";
	std::string login_fin     	 	 = login_ori + appid + ", work_dir = .";
	const char* login_params = login_fin.c_str();//登录参数,appid与msc库绑定,请勿随意改动

	cout<< ">>>>>>> login_params:"<< login_params<< endl;


	/* 用户登录 */
	ret = MSPLogin(NULL, NULL, login_params); //第一个参数是用户名，第二个参数是密码，第三个参数是登录参数，用户名和密码可在http://www.xfyun.cn注册获取
	if (MSP_SUCCESS != ret){
		printf("MSPLogin failed, error code: %d.\n", ret);
		MSPLogout(); //退出登录
		return;
		//goto exit ;//登录失败，退出登录
	}
}

TTS::~TTS(){
	MSPLogout(); //退出登录
	RCLCPP_INFO(this->get_logger(),"tts_node over!\n");
} 

int main(int argc,char **argv)
{
	// rclcpp::init(argc,argv);
	// TTS tts_make("tts_node",rclcpp::NodeOptions());
	// if (tts_make.init() == 0){
	// 	RCLCPP_INFO(rclcpp::get_logger("tts_node"),
	// 			"tts_node done!");
	// 	}
	// else{
	// 	RCLCPP_INFO(rclcpp::get_logger("tts_node"),
	// 			"tts_node Interrupted!");
	// 	}
	// return 0;

	rclcpp::init(argc,argv);
    auto tts_make = std::make_shared<TTS>("tts_node",rclcpp::NodeOptions());
    rclcpp::spin(tts_make);
    rclcpp::shutdown();
    return 0;
}

void TTS::tts_text_callback(const std_msgs::msg::String::SharedPtr msg) {
	if (busy_) {
        RCLCPP_WARN(this->get_logger(), "TTS 正在合成中，忽略本次请求");
        return;
    }
	else
	{
		busy_ = true;
    	tts_text = msg->data;
    	this->init();  // 每收到一次新文本就合成并播报
		busy_ = false;
	}
    
}
