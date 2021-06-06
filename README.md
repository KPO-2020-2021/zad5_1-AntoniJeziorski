
## Uruchamianie programu
1. Nalezy stworzyc folder "build" jesli nie istnieje i nastepnie zbudowac w nim plik MakeFile przy uzyciu polecenia "cmake ..".
2. Po zbudowaniu pliku MakeFile w folderze build nalezy uzyc polecenia make.
3. Po kompilacji mozna uruchomic program poleceniem ./main bedac w folderze build.

## Dokumentacja
Wygenerowana dokumentacja znajduje sie w pliku "index.html" w folderze dox.

## Testy
Po kompilacji w folderez build mozna uzyc polecenia ./unit_tests -s, aby wykonac testy i sprawdzic poprawnosc dzialania programu.

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make test      #### Compile the tests
> ./unit_tests -s   #### Start the tests, -s flag - full description of each case
> make fulltest #### alternative for above, compile & run tests with full decription
> make coverage  #### Generate a coverage report
> make doc       #### Generate html documentation
```

Things to remember:
* changes to CMakeLists.txt in the main folder with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/example.cpp
    src/lacze_do_gnuplota.cpp
    src/cuboid.cpp
    src/drone.cpp
    src/matrix3D.cpp
    src/solid.cpp
    src/scene.cpp
    src/hexagonal_prism.cpp
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp # etc.
)
set(LIBRARY_NAME zadX)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    test_matrix3D.cpp
    test_vector3D.cpp
    test_solid.cpp
    test_cuboid.cpp
    test_hexagonal_prism.cpp
    test_drone.cpp
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

