{
  "targets": [
    {
      "target_name": "threejs",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [
        "addon/threejs.cpp",
        "addon/gen/V8Box2.cpp",
        "addon/gen/V8Box2.h",
        "addon/impl/Box2.cpp",
        "addon/impl/Box2.h"
      ]
    }
  ]
}
