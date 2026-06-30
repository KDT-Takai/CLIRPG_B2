#pragma once
#include <string>

namespace System {
    namespace Entity {
        /// <summary>
        /// Tag for local entities (scene-scoped objects).
        /// </summary>
        struct LocalObjectTag {};
        
        /// <summary>
        /// Tag for global entities (persistent objects across scenes).
        /// </summary>
        struct GlobalObjectTag {};
    }
}
