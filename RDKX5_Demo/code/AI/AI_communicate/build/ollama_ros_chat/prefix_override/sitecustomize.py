import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sunrise/AI/AI_communicate/install/ollama_ros_chat'
