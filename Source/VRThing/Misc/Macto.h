#pragma once
#define INIT_COMPONENT(ComponentClass, Member, ...) Member = CreateDefaultSubobject<ComponentClass>(GET_MEMBER_NAME_CHECKED(ThisClass, Member), ##__VA_ARGS__)