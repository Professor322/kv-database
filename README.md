# kv-database
## Хранилище, реализованное на C++, использующее в качестве сетевой библиотеки boost::asio
## Данные хранятся в хэштаблице, где ключ - это строка, а значение - JSON

Работоспосбность клиента и сервера проверена на Ubuntu 18.04
Необходимый минимум: **g++, libboost-all-dev, cmake, make**

Для установки необходимых покетов на Ubuntu воспользуйтесь командой:
- **sudo apt-get install g++ libboost-all-dev cmake make**

Для того, чтобы скомпилировать клиент и сервер необходимо:

- склонить репозиторий в папку текущего пользователя **~/**
  
  Из корня репозитория запустить команды:
  - cmake CMakelist.txt
  - make
  
При успешной компиляции появятся два бинарных файла **client** и **server**

# Server:

Сервер имеет опции запуска:
  - Если не подавать в него никаких аргументов, то сервер начнет слушать по лупбэк адресу и порту 8001
  - Первый аргумент специфицирует ip-адрес, второй - порт. При запуске с одним аргументов изменяется только адрес,
  при запуске с двумя аргументами - адрес и порт.
  
# Client

Клиент имеет такие же опции запуска.

Клиент примнимает запросы в таком виде, в котором было указано в сообщении. А именно:
- POST /kv body: {key: "test", "value": {SOME ARBITRARY JSON}}
- PUT kv/{id} body: {"value": {SOME ARBITRARY JSON}}
- GET kv/{id}
- DELETE kv/{id}

То есть, один запрос - одна строчка.
И формирует из них корректные HTTP запросы.

# Обработка запросов

Request | OK | Incorrect body | Key already exist | No such key
--- | --- | --- | --- |--- 
POST | Code: 200 | Code: 400 | Code: 409 | - 
PUT | Code: 200 | Code: 400 | - | - | Code:404 
GET | Code 200 Body: key: "key" value: {JSON}| - | - | Code: 404 
DELETE | Code 200 | - | - | Code: 404 

Для выхода из клиента и из сервера используется **Ctrl + C**
