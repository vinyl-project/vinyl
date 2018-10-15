#undef _DEBUG
#include <python.h>
#include <numpy/arrayobject.h>
#include <vinyl/vinyl-c.h>

PyObject* vinyl_init(PyObject* self, PyObject* args);
PyObject* vinyl_left_click(PyObject* self, PyObject* args);
PyObject* vinyl_right_click(PyObject* self, PyObject* args);
PyObject* vinyl_middle_click(PyObject* self, PyObject* args);

PyObject* vinyl_left_up(PyObject* self, PyObject* args);
PyObject* vinyl_right_up(PyObject* self, PyObject* args);
PyObject* vinyl_middle_up(PyObject* self, PyObject* args);

PyObject* vinyl_left_down(PyObject* self, PyObject* args);
PyObject* vinyl_right_down(PyObject* self, PyObject* args);
PyObject* vinyl_middle_down(PyObject* self, PyObject* args);

PyObject* vinyl_left_double_click(PyObject* self, PyObject* args);

PyObject* vinyl_move_to(PyObject* self, PyObject* args);
PyObject* vinyl_move(PyObject* self, PyObject* args);
PyObject* vinyl_mouse_wheel(PyObject* self, PyObject* args);

PyObject* vinyl_key_down(PyObject* self, PyObject* args);
PyObject* vinyl_key_up(PyObject* self, PyObject* args);
PyObject* vinyl_key_click(PyObject* self, PyObject* args);

PyObject* vinyl_is_key_down(PyObject* self, PyObject* args);
PyObject* vinyl_is_key_up(PyObject* self, PyObject* args);
PyObject* vinyl_is_mouse_button_down(PyObject* self, PyObject* args);
PyObject* vinyl_is_mouse_button_up(PyObject* self, PyObject* args);

PyObject* vinyl_get_mouse_pos(PyObject* self, PyObject* args);
PyObject* vinyl_get_desktop_size(PyObject* self, PyObject* args);

PyObject* vinyl_sleep(PyObject* self, PyObject* args);
PyObject* vinyl_message_box(PyObject* self, PyObject* args);
PyObject* vinyl_trace_print(PyObject* self, PyObject* args);
PyObject* vinyl_command(PyObject* self, PyObject* args);
PyObject* vinyl_say_string(PyObject* self, PyObject* args);

PyObject* vinyl_screenshot(PyObject* self, PyObject* args);

static PyMethodDef VinylMethods[] = {
    {"init", vinyl_init, METH_VARARGS,
     "A function that inits vinyl."},
	{ "left_click", vinyl_left_click, METH_VARARGS,
	"A function that controls mouse to left click." },
	{ "right_click", vinyl_right_click, METH_VARARGS,
	"A function that controls mouse to right click." },
	{ "middle_click", vinyl_middle_click, METH_VARARGS,
	"A function that controls mouse to middle click." },
	{ "left_up", vinyl_left_up, METH_VARARGS,
	"A function that controls mouse to left up." },
	{ "right_up", vinyl_right_up, METH_VARARGS,
	"A function that controls mouse to right up." },
	{ "middle_up", vinyl_middle_up, METH_VARARGS,
	"A function that controls mouse to middle up." },
	{ "left_down", vinyl_left_down, METH_VARARGS,
	"A function that controls mouse to left down." },
	{ "right_down", vinyl_right_down, METH_VARARGS,
	"A function that controls mouse to right down." },
	{ "middle_down", vinyl_middle_down, METH_VARARGS,
	"A function that controls mouse to middle down." },
	{ "left_double_click", vinyl_left_double_click, METH_VARARGS,
	"A function that controls mouse to left double click." },
	{ "key_down", vinyl_key_down, METH_VARARGS,
	"A function that presses key down." },
	{ "key_up", vinyl_key_up, METH_VARARGS,
	"A function that releases key up." },
	{ "key_click", vinyl_key_click, METH_VARARGS,
	"A function that clicks key." },
	{ "move_to", vinyl_move_to, METH_VARARGS,
	"A function that controls mouse to move." },
	{ "move", vinyl_move, METH_VARARGS,
	"A function that controls mouse to relative move." },
	{ "mouse_wheel", vinyl_mouse_wheel, METH_VARARGS,
	"A function that controls mouse wheel." },
	{ "get_desktop_size", vinyl_get_desktop_size, METH_VARARGS,
	"A function that gets size of desktop." },
	{ "get_mouse_pos", vinyl_get_mouse_pos, METH_VARARGS,
	"A function that gets position of mouse." },
	{ "is_key_down", vinyl_is_key_down, METH_VARARGS,
	"A function that gets key state." },
	{ "is_key_up", vinyl_is_key_up, METH_VARARGS,
	"A function that gets key state." },
	{ "is_mouse_button_down", vinyl_is_mouse_button_down, METH_VARARGS,
	"A function that gets mouse state." },
	{ "is_mouse_button_up", vinyl_is_mouse_button_up, METH_VARARGS,
	"A function that gets mouse state." },
	{ "sleep", vinyl_sleep, METH_VARARGS,
	"A function that hangs up the thread." },
	{ "message_box", vinyl_message_box, METH_VARARGS,
	"A function that opens a message box." },
	{ "trace_print", vinyl_trace_print, METH_VARARGS,
	"A function that prints information in console." },
	{ "cmd", vinyl_command, METH_VARARGS,
	"A function that executes a command." },
	{ "say_string", vinyl_say_string, METH_VARARGS,
	"A function that outputs a string." },
	{ "screenshot", vinyl_screenshot, METH_VARARGS,
	"A function that captures screenshot." },
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// module exceptions
static PyObject* StdErrorObj;

// module methods
static struct PyModuleDef vinyl_module = {
    PyModuleDef_HEAD_INIT,
    "vinyl",   /* name of module */
    "vinyl module", /* module documentation */
    -1,
    VinylMethods
};

// module init
PyMODINIT_FUNC
PyInit_vinyl(void)
{
    PyObject* m = PyModule_Create(&vinyl_module);
    if (m == NULL) {
        return NULL;
    }

    // Set up all exceptions.
	StdErrorObj = PyErr_NewException("vinyl.StdError", NULL, NULL);
    Py_INCREF(StdErrorObj);
    PyModule_AddObject(m, "StdError", StdErrorObj);

	// import third-party modules
	import_array();

	// vinyl init
	VinylInit("");

    return m;
}

PyObject* vinyl_init(PyObject* self, PyObject* args)
{
    char *profile;
    if (!(PyArg_ParseTuple(args, "s", &profile))) {
        return NULL;
    }

    // init input
	try
	{
		VinylInit(profile);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_left_click(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonClick(vinyl::input::InputButton::Code::Left, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_right_click(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonClick(vinyl::input::InputButton::Code::Right, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_middle_click(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonClick(vinyl::input::InputButton::Code::Right, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_left_up(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonUp(vinyl::input::InputButton::Code::Left, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_right_up(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonUp(vinyl::input::InputButton::Code::Right, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_middle_up(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonUp(vinyl::input::InputButton::Code::Middle, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_left_down(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonDown(vinyl::input::InputButton::Code::Left, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_right_down(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonDown(vinyl::input::InputButton::Code::Right, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_middle_down(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonDown(vinyl::input::InputButton::Code::Middle, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_left_double_click(PyObject* self, PyObject* args)
{
	try
	{
		VinylMouseButtonDoubleClick(vinyl::input::InputButton::Code::Left, 0, 0);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_move_to(PyObject* self, PyObject* args)
{
	int x, y;
	if (!(PyArg_ParseTuple(args, "ii", &x, &y)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylMouseMoveTo(x, y);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_move(PyObject* self, PyObject* args)
{
	int x, y;
	if (!(PyArg_ParseTuple(args, "ii", &x, &y)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylMouseMove(x, y);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_mouse_wheel(PyObject* self, PyObject* args)
{
	float delta;
	if (!(PyArg_ParseTuple(args, "f", &delta)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		if (delta > 0)
		{
			while(delta-->0)
				VinylWheelUp();
		}
		else
		{
			while (delta++<0)
				VinylWheelDown();
		}
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_sleep(PyObject* self, PyObject* args)
{
	std::uint32_t milliseconds;
	if (!(PyArg_ParseTuple(args, "i", &milliseconds)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylSleep(milliseconds);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_message_box(PyObject* self, PyObject* args)
{
	const char * msg;
	if (!(PyArg_ParseTuple(args, "s", &msg)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylMessageBox(nullptr, msg);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_trace_print(PyObject* self, PyObject* args)
{
	std::uint8_t enable;
	if (!(PyArg_ParseTuple(args, "b", &enable)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylTracePrint(enable);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_command(PyObject* self, PyObject* args)
{
	const char * cmd;
	if (!(PyArg_ParseTuple(args, "s", &cmd)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylCommand(cmd);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_key_down(PyObject* self, PyObject* args)
{
	int code;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylKeyDown(static_cast<vinyl::input::InputKey::Code>(code));
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_key_up(PyObject* self, PyObject* args)
{
	int code;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylKeyUp(static_cast<vinyl::input::InputKey::Code>(code));
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_key_click(PyObject* self, PyObject* args)
{
	int code;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylKeyClick(static_cast<vinyl::input::InputKey::Code>(code));
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_get_mouse_pos(PyObject* self, PyObject* args)
{
	std::uint16_t x, y;
	PyObject *pos_tuple = nullptr;
	try
	{
		VinylGetMousePos(x, y);
		pos_tuple = PyTuple_New(2);
		if (pos_tuple)
		{
			PyTuple_SET_ITEM(pos_tuple, 0, PyLong_FromLong(x));
			PyTuple_SET_ITEM(pos_tuple, 1, PyLong_FromLong(y));
		}
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	return pos_tuple;
}

PyObject* vinyl_get_desktop_size(PyObject* self, PyObject* args)
{
	std::uint16_t w, h;
	PyObject *size_tuple = nullptr;
	try
	{
		VinylGetWindowSize(nullptr, w, h);
		size_tuple = PyTuple_New(2);
		if (size_tuple)
		{
			PyTuple_SET_ITEM(size_tuple, 0, PyLong_FromLong(w));
			PyTuple_SET_ITEM(size_tuple, 1, PyLong_FromLong(h));
		}
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	return size_tuple;
}

PyObject* vinyl_is_key_down(PyObject* self, PyObject* args)
{
	bool result = false;
	int code;
	std::uint8_t state;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylIsKeyDown(static_cast<vinyl::input::InputKey::Code>(code), state);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	return PyBool_FromLong(state);
}

PyObject* vinyl_is_key_up(PyObject* self, PyObject* args)
{
	bool result = false;
	int code;
	std::uint8_t state;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylIsKeyUp(static_cast<vinyl::input::InputKey::Code>(code), state);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	return PyBool_FromLong(state);
}

PyObject* vinyl_is_mouse_button_down(PyObject* self, PyObject* args)
{
	bool result = false;
	int code;
	std::uint8_t state;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylIsMouseButtonDown(static_cast<vinyl::input::InputButton::Code>(code), state);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	return PyBool_FromLong(state);
}

PyObject* vinyl_is_mouse_button_up(PyObject* self, PyObject* args)
{
	bool result = false;
	int code;
	std::uint8_t state;
	if (!(PyArg_ParseTuple(args, "i", &code)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylIsMouseButtonUp(static_cast<vinyl::input::InputButton::Code>(code), state);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	return PyBool_FromLong(state);
}

PyObject* vinyl_say_string(PyObject* self, PyObject* args)
{
	const char* text;
	if (!(PyArg_ParseTuple(args, "s", &text)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		VinylSayString(nullptr, text);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}

PyObject* vinyl_screenshot(PyObject* self, PyObject* args)
{
	int x, y, w, h;
	if (!(PyArg_ParseTuple(args, "iiii", &x, &y, &w, &h)))
	{
		Py_RETURN_NONE;
	}

	try
	{
		auto data = std::make_unique<std::uint8_t[]>(w * h * 3);
		npy_intp dims[3] = { h, w, 3 };

		// TODO get w h
		VinylScreenshot(nullptr, x, y, w, h, data.get());
		PyObject* nd_array = PyArray_SimpleNew(3, dims, NPY_UINT8);
		char * raw_data = PyArray_BYTES(nd_array);
		std::memcpy(raw_data, data.get(), w * h * 3);
		return nd_array;
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(StdErrorObj, e.what());
	}

	Py_RETURN_NONE;
}