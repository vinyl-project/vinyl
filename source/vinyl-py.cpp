

#include <python.h>

PyObject* VinylInit(PyObject* profile);
void VinylWindowKeyDown(vinyl::input::InputKey::Code key);
void VinylWindowKeyDown(vinyl::input::InputKey::Code key);
void VinylWindowKeyUp(vinyl::input::InputKey::Code key);
void VinylWindowKeyPress(vinyl::input::InputKey::Code key);
void VinylWindowKeyChar(std::uint16_t unicode, std::uint16_t mods);
void VinylWindowMouseButtonDown(vinyl::input::InputButton::Code button, float x, float y);
void VinylWindowMouseButtonUp(vinyl::input::InputButton::Code button, float x, float y);
void VinylWindowMouseButtonDoubleClick(vinyl::input::InputButton::Code button, float x, float y);
void VinylWindowMouseMotion(float x, float y);
void VinylScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h);

static PyMethodDef VinylMethods[] = {
    {"VinylInit", VinylInit, METH_VARARGS,
     "A function that prints a list of strings."},
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



PyObject* VinylInit(PyObject* self, PyObject* args)
{
    char *profile;
    if (!(PyArg_ParseTuple(args, "s", &orignal))) {
        return NULL;
    }
    Py_RETURN_NONE;
}