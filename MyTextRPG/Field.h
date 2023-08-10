#pragma once

enum FieldType
{
	FT_Monster,
	FT_Treasure,
	FT_NPC
};

class Field
{
public:
	Field();
	virtual ~Field();

	int _fieldType;
};