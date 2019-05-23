#pragma once

void openFileForRead(std::fstream& file, char  path[50]);

void addContract(std::fstream& file, char  path[50], ContractUI& mUI, Contract& mContract);

void deleteContract(std::fstream& file, char  path[50], Contract& mContract, ContractUI& mUI);

void updateContract(std::fstream& file, char  path[50], Contract& mContract, ContractUI& mUI);

void readContract(std::fstream& file, char  path[50], Contract& mContract, ContractUI& mUI);

void exit(std::fstream& file);

void openFileForWrite(std::fstream& file, char  path[50]);
