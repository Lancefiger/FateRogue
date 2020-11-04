#pragma once

#include "Class.h"
#include "Scene.h"
#include "Player.h"
#include "Coordinate.h"

static Scene SceneInstance = Scene(Exemplar());
static Player PlayerInstance = Player(Exemplar());
static Coordinate CoordinateInstance = Coordinate(Exemplar());
