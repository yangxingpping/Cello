#include "Cello.h"


struct Demo{
    int m_x;
};

static const char* Demo_Name(void) {
  return "Demo";
}

static const char* Demo_Brief(void) {
  return "Operating System Demo";
}

static const char* Demo_Description(void) {
  return
    "The `Demo` type is a wrapper of the native C `Demo` type representing a "
    "file in the operating system.";
}

static const char* Demo_Definition(void) {
  return
    "struct Demo {\n"
    "  Demo* file;\n"
    "};\n";
}

static struct Example* Demo_Examples(void) {
  
  static struct Example examples[] = {
    {
      "Usage",
      "var x = new(Demo, $S(\"test.bin\"), $S(\"wb\"));\n"
      "char* data = \"hello\";\n"
      "swrite(x, data, strlen(data));\n"
      "sclose(x);\n"
    }, {NULL, NULL}
  };

  return examples;
  
}

static void Demo_Open(var self);
static void Demo_Close(var self);

static void Demo_New(var self, var args) {
    printf("demo new function\n");
}

static void Demo_Del(var self) {
    printf("demo del function\n");
}

static void Demo_Close(var self) {
    printf("demo close\n");
}

static void Demo_Open(var self){
    printf("demo open\n");
}


var Demo = Cello(Demo,
  Instance(Doc,
    Demo_Name,       Demo_Brief,    Demo_Description, 
    Demo_Definition, Demo_Examples, NULL),
  Instance(New, Demo_New, Demo_Del),
  Instance(Start, Demo_Open, Demo_Close, NULL));
