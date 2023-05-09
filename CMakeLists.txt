cmake_minimum_required(VERSION 3.25)
project(dinocaust)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/SDL2-devel-2.26.5-VC/SDL2-2.26.5/include)
set(SDL2_LIB_DIR C:/SDL2-devel-2.26.5-VC/SDL2-2.26.5/lib/x64)

set(SDL2MIXER_INCLUDE_DIR "C:/SDL2_mixer-devel-2.6.3-VC/SDL2_mixer-2.6.3/include")
set(SDL2MIXER_LIB_DIR "C:/SDL2_mixer-devel-2.6.3-VC/SDL2_mixer-2.6.3/lib/x64")

set(SDL2IMAGE_INCLUDE_DIR "C:/SDL2_image-devel-2.6.3-VC/SDL2_image-2.6.3/include")
set(SDL2IMAGE_LIB_DIR "C:/SDL2_image-devel-2.6.3-VC/SDL2_image-2.6.3/lib/x64")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp src/main/Engine.cpp src/main/Engine.h src/graphics/TextureHandler.cpp src/graphics/TextureHandler.h src/physics/Vector2D.h src/physics/Transform.h src/object/Object.h src/object/GameObject.h src/characters/Character.h src/characters/Dino.cpp src/characters/Dino.h src/animation/Animation.cpp src/animation/Animation.h src/physics/RigidBody.h src/inputs/Input.cpp src/inputs/Input.h src/main/Timer.cpp src/main/Timer.h src/collision/CollisionHandler.cpp src/collision/CollisionHandler.h src/collision/Collider.h src/characters/Enemy.cpp src/characters/Enemy.h src/util/NumberGenerator.cpp src/util/NumberGenerator.h)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib ${SDL2MIXER_LIB_DIR}/SDL2_mixer.lib ${SDL2IMAGE_LIB_DIR}/SDL2_image.lib)
