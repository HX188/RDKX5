from setuptools import find_packages
from setuptools import setup

setup(
    name='rdk_ai_gateway_msg',
    version='0.0.0',
    packages=find_packages(
        include=('rdk_ai_gateway_msg', 'rdk_ai_gateway_msg.*')),
)
