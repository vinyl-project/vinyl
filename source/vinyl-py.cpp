#undef _DEBUG
#include <python.h>
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

PyObject* vinyl_sleep(PyObject* self, PyObject* args);
PyObject* vinyl_message_box(PyObject* self, PyObject* args);
PyObject* vinyl_trace_print(PyObject* self, PyObject* args);
PyObject* vinyl_command(PyObject* self, PyObject* args);

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
	{ "sleep", vinyl_sleep, METH_VARARGS,
	"A function that hangs up the thread." },
	{ "message_box", vinyl_message_box, METH_VARARGS,
	"A function that opens a message box." },
	{ "trace_print", vinyl_trace_print, METH_VARARGS,
	"A function that prints information in console." },
	{ "cmd", vinyl_command, METH_VARARGS,
	"A function that execute a command." },
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
		VinylMessageBox(msg);
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