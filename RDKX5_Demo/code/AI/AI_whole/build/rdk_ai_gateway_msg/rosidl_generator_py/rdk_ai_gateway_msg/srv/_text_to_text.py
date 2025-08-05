# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rdk_ai_gateway_msg:srv/TextToText.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TextToText_Request(type):
    """Metaclass of message 'TextToText_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rdk_ai_gateway_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rdk_ai_gateway_msg.srv.TextToText_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__text_to_text__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__text_to_text__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__text_to_text__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__text_to_text__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__text_to_text__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TextToText_Request(metaclass=Metaclass_TextToText_Request):
    """Message class 'TextToText_Request'."""

    __slots__ = [
        '_input',
        '_model',
    ]

    _fields_and_field_types = {
        'input': 'string',
        'model': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.input = kwargs.get('input', str())
        self.model = kwargs.get('model', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.input != other.input:
            return False
        if self.model != other.model:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def input(self):  # noqa: A003
        """Message field 'input'."""
        return self._input

    @input.setter  # noqa: A003
    def input(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'input' field must be of type 'str'"
        self._input = value

    @builtins.property
    def model(self):
        """Message field 'model'."""
        return self._model

    @model.setter
    def model(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model' field must be of type 'str'"
        self._model = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TextToText_Response(type):
    """Metaclass of message 'TextToText_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rdk_ai_gateway_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rdk_ai_gateway_msg.srv.TextToText_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__text_to_text__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__text_to_text__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__text_to_text__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__text_to_text__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__text_to_text__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TextToText_Response(metaclass=Metaclass_TextToText_Response):
    """Message class 'TextToText_Response'."""

    __slots__ = [
        '_output',
    ]

    _fields_and_field_types = {
        'output': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.output = kwargs.get('output', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.output != other.output:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def output(self):
        """Message field 'output'."""
        return self._output

    @output.setter
    def output(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'output' field must be of type 'str'"
        self._output = value


class Metaclass_TextToText(type):
    """Metaclass of service 'TextToText'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rdk_ai_gateway_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rdk_ai_gateway_msg.srv.TextToText')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__text_to_text

            from rdk_ai_gateway_msg.srv import _text_to_text
            if _text_to_text.Metaclass_TextToText_Request._TYPE_SUPPORT is None:
                _text_to_text.Metaclass_TextToText_Request.__import_type_support__()
            if _text_to_text.Metaclass_TextToText_Response._TYPE_SUPPORT is None:
                _text_to_text.Metaclass_TextToText_Response.__import_type_support__()


class TextToText(metaclass=Metaclass_TextToText):
    from rdk_ai_gateway_msg.srv._text_to_text import TextToText_Request as Request
    from rdk_ai_gateway_msg.srv._text_to_text import TextToText_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
