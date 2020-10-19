#include "Cello.h"


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
	struct Demo* p = self;
    printf("demo new function\n");
	size_t arglen = len(args);
	if (len(args) > 0)
	{
		p->userAlloc = get(args, $I(0));
		p->userDelloc = get(args, $I(1));
		arglen = len(args);
		p->allocArgs = args;// new(Tuple, args);
		//p->allocArgs = args;
	}
	arglen = len(p->allocArgs);
	Demo_Open(self);
}

static void Demo_Del(var self) {
	//Demo_Close(self);
    printf("demo del function\n");
	
}

static void Demo_Close(var self) {
    printf("demo close\n");
	struct Demo* p = self;
	if (p)
	{
		call(p->userDelloc, self);
	}
	if (p->userAlloc)
	{
		del(p->userAlloc);
		p->userAlloc = NULL;
	}
	if (p->userDelloc)
	{
		del(p->userDelloc);
		p->userAlloc = NULL;
	}
	del(self);
}

static void Demo_Open(var self){
    printf("demo open\n");
	struct Demo* p = self;
	if (p)
	{
		size_t arglen = len(p->allocArgs);
		call(p->userAlloc, self, p->allocArgs);
	}
}


var Demo = Cello(Demo,
  Instance(Doc,
    Demo_Name,       Demo_Brief,    Demo_Description, 
    Demo_Definition, Demo_Examples, NULL),
  Instance(New, Demo_New, Demo_Del),
  Instance(Start, NULL, Demo_Close, NULL));
