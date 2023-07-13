#pragma once
#define INIT_COMPONENT(ComponentClass, Member, ...) Member = CreateDefaultSubobject<ComponentClass>(GET_MEMBER_NAME_CHECKED(ThisClass, Member), ##__VA_ARGS__)

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
public:\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
protected:\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)