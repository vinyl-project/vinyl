

#include <python.h>

PyObject* vinyl_init(PyObject* self, PyObject* args);

static PyMethodDef VinylMethods[] = {
    {"init", vinyl_init, METH_VARARGS,
     "A function that inits vinyl."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef vinyl_module = {
    PyModuleDef_HEAD_INIT,
    "vinyl",   /* name of module */
    "vinyl module", /* module documentation */
    -1,
    VinylMethods
};

PyMODINIT_FUNC
PyInit_vinyl(void)
{
    PyObject* m = PyModule_Create(&vinyl_module);
    if (m == NULL) {
        return NULL;
    }
    // Set up all exceptions.
    /*
    BaseErrorObj = PyErr_NewException("spam.BaseError", NULL, NULL);
    Py_INCREF(BaseErrorObj);
    PyModule_AddObject(m, "BaseError", BaseErrorObj);
    IntegerErrorObj = PyErr_NewException("spam.IntegerError", BaseErrorObj, NULL);
    Py_INCREF(IntegerErrorObj);
    PyModule_AddObject(m, "IntegerError", IntegerErrorObj);
    PositivityErrorObj = PyErr_NewException("spam.PositivityError", BaseErrorObj, NULL);
    Py_INCREF(PositivityErrorObj);
    PyModule_AddObject(m, "PositivityError", PositivityErrorObj);
    */
    return m;
}



PyObject* vinyl_init(PyObject* self, PyObject* args)
{
    char *profile;
    if (!(PyArg_ParseTuple(args, "s", &profile))) {
        return NULL;
    }
    // Py_RETURN_NONE;
    return PyBool_FromLong(1);
}