#undef _DEBUG
#include <python.h>
#include <vinyl/input.h>
#include <vinyl/vinyl-c.h>

extern vinyl::input::IInputPtr input_;

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

static PyMethodDef VinylMethods[] = {
    {"init", vinyl_init, METH_VARARGS,
     "A function that inits vinyl."},
	{ "left_click", vinyl_left_click, METH_VARARGS,
	"A function that control mouse to left click." },
	{ "right_click", vinyl_right_click, METH_VARARGS,
	"A function that control mouse to right click." },
	{ "middle_click", vinyl_middle_click, METH_VARARGS,
	"A function that control mouse to middle click." },
	{ "left_up", vinyl_left_up, METH_VARARGS,
	"A function that control mouse to left up." },
	{ "right_up", vinyl_right_up, METH_VARARGS,
	"A function that control mouse to right up." },
	{ "middle_up", vinyl_middle_up, METH_VARARGS,
	"A function that control mouse to middle up." },
	{ "left_down", vinyl_left_down, METH_VARARGS,
	"A function that control mouse to left down." },
	{ "right_down", vinyl_right_down, METH_VARARGS,
	"A function that control mouse to right down." },
	{ "middle_down", vinyl_middle_down, METH_VARARGS,
	"A function that control mouse to middle down." },
	{ "left_double_click", vinyl_left_double_click, METH_VARARGS,
	"A function that control mouse to left double click." },
	{ "move_to", vinyl_move_to, METH_VARARGS,
	"A function that control mouse to move." },
	{ "move", vinyl_move, METH_VARARGS,
	"A function that control mouse to relative move." },
	{ "mouse_wheel", vinyl_mouse_wheel, METH_VARARGS,
	"A function that control mouse wheel." },
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