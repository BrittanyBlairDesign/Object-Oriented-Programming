#pragma once

using Entity = long;

Entity nextEntity = 0;

Entity CreateEntity() { return nextEntity++; }