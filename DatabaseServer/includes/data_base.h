//
// Created by professor on 20.03.20.
//

#pragma once

#include <json.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "server.h"
#include "data_container.h"
#include "query_parser.h"

#define LOG_FILE "./logs/log.txt"

class DataBase {
private:
	std::unordered_map<std::string, DataContainer> db;
	std::fstream logs;
	bool without_log;
	QueryType  current_query;
public:
	explicit DataBase(const char* log_filname);
	void help();
	void postElem(const Query& q);
	void putElem(const Query& q);
	void getElem(const Query& q) const;
	void deleteElem(const Query& q);
	void setCurrentQuery(const QueryType& type);
	void logCommand(const std::string& command);
	QueryType getCurrentQuery() const;
	bool 	  getWithoutLog() const;
	~DataBase();
};

std::istream& operator >> (std::istream& is, DataBase& db);