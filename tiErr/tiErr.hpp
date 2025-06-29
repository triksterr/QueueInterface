#pragma once
#ifndef TIERR_HPP
#define TIERR_HPP

#include <chrono>

#include <thread>

#include <string>

enum ErrType
{
	
	NOER,	
	N_DT,	
	M_AL,	
	M_FR,	
	O_CR,	
	O_DL,	
	D_RD,	
	В_WR,	
	PAR_,	
	ACC_,	
	TRD_,	
	O_NE,	
	
	NONC,	
	REPE, 	
	USER,	
	CRIT,	
	UNKE	
};

struct ErrDesc
{
	ErrType type;	
	std::string descr;	
};

ErrDesc ErrDescr[] = 
{
	
	{NOER, "no error"},
	{N_DT, "no data"},
	{M_AL, "memory allocation error"},
	{M_FR, "memory free error"},
	{O_CR, "object creation error"},
	{O_DL, "object deletion error"},
	{D_RD, "data reading error"},
	{В_WR, "data writing error"},
	{PAR_, "parameter error"},
	{ACC_, "access error"},
	{TRD_, "multitread error"},
	{O_NE, "object not exists"},
	
	{NONC, "non critical error"},
	{REPE, "reparable error"},
	{USER, "need user reaction"},
	{CRIT, "critical error"},
	{UNKE, "unknown error"}
};

class tiError
{
public:
	
	tiError();
	
	~tiError();

private:
	unsigned int DI = 0; 
	ErrType Elevel;	
	ErrType Etype;	
	
	std::thread::id Ethread; 
	std::chrono::time_point<std::chrono::system_clock> Etime;	
	unsigned int Eflow; 
	unsigned int Eline;	
	std::string Efunc;	
	std::string Efile;	
	std::string Etext;	
};

#endif 