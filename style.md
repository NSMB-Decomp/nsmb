<!-- TODO: Improvements -->

# Style

## Definitions
* **Object** - A C++ Class object
* **Entity / Actor** - TODO: Should this be named entity or actor? How best to define it?
* 

## Casing
* **variables** - snake_case
* **functions** - camelCase
* **class** - PascalCase

## Exceptions
<!-- Things that have a common name or are a exception to the above rules? -->
* `__stub` - If a function does nothing and its purpose is unknown then name it __stub.
* `Class::__operator_delete` - https://en.cppreference.com/w/cpp/memory/new/operator_delete
* `Class::__operator_new` - https://en.cppreference.com/w/cpp/memory/new/operator_new.html
* `Class::profile` - The location that holds the object profile
* `Class::vtable` - The location that holds the vtable
* `Class::Object` - Create a object
* `Class::~Object` - Destroy a object