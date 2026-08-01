# OpenGL Practice

Practice code and exercises while learning OpenGL from [LearnOpenGL.com](https://learnopengl.com/).

## About

This repo tracks my progress through the LearnOpenGL tutorials — from basic setup through shaders, textures, lighting, and beyond.

## Structure

```
├── 01_getting_started/
│   ├── hello_window/
│   ├── hello_triangle/
│   └── shaders/
├── 02_lighting/
├── 03_model_loading/
└── 04_advanced_opengl/
```

## Build

- **Language:** C++
- **Libraries:** GLFW, GLAD, GLM
- **Build system:** CMake (using CMake GUI)
- **IDE:** Visual Studio 2022

**Steps:**
1. Open CMake GUI
2. Set "Where is the source code" to the repo root
3. Set "Where to build the binaries" to a `build/` folder
4. Click **Configure**, select **Visual Studio 17 2022** as the generator
5. Click **Generate**
6. Click **Open Project** (or open the generated `.sln` file in `build/`)
7. Build and run from Visual Studio (set the desired example as the Startup Project if the repo has multiple)

## Progress

- [x] Setting up OpenGL context (GLFW + GLAD)
- [x] Hello Window
- [ ] Hello Triangle
- [ ] Shaders
- [ ] Textures
- [ ] Transformations
- [ ] Coordinate Systems
- [ ] Camera
- [ ] Lighting basics
- [ ] Model loading

## Notes

Just a personal learning repo — code here is for practice, not production. Feel free to browse if you're also working through LearnOpenGL!
