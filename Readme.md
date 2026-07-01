MiniRedis/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── data/
│   └── dump.rdb                # Saved database
│
├── docs/
│   ├── architecture.md
│   └── commands.md
│
├── include/
│   ├── Config.h
│   ├── RedisServer.h
│   ├── CommandParser.h
│   ├── StorageEngine.h
│   ├── TTLManager.h
│   ├── Persistence.h
│   ├── CommandExecutor.h
│   └── Utils.h
│
├── src/
│   ├── main.cpp
│   ├── RedisServer.cpp
│   ├── CommandParser.cpp
│   ├── StorageEngine.cpp
│   ├── TTLManager.cpp
│   ├── Persistence.cpp
│   ├── CommandExecutor.cpp
│   └── Utils.cpp
│
├── tests/
│   ├── test_storage.cpp
│   ├── test_parser.cpp
│   └── test_ttl.cpp
│
└── client/
    └── redis_cli.cpp           # Optional client