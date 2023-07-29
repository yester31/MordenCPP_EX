#pragma once
//#define HAS_USING_ENUMS

#ifdef HAS_USING_ENUMS
#include <string_view>
#endif

namespace recipe_1_06
{
    
    // //범위가 지정되지 않은 열거형
    //enum Status { Unknown, Created, Connected };

    //enum Codes
    //{
    //   OK,
    //   Failure,
    //    Unknown //redefinition
    //};
    

    
    //namespace Status
    //{
    //   enum Status { Unknown, Created, Connected };
    //};

    //namespace Codes
    //{
    //   enum Codes { OK, Failure, Unknown };
    //};
    

    // 범위가 지정된 열거형
    enum class Status
    {
        Unknown,
        Created,
        Connected
    };
    enum class Codes
    {
        OK,
        Failure,
        Unknown
    };
    enum class Codes2 : unsigned int; // 명시적인 기본 타입 지정
    void print_code(Codes2 const code) {}
    enum class Codes2 : unsigned int
    {
        OK = 0,
        Failure = 1,
        Unknown = 0xFFFF0000U
    };

#ifdef HAS_USING_ENUMS
    struct foo
    {
        enum class Status
        {
            Unknown,
            Created,
            Connected
        };

        using enum Status;
    };

    void process(Status const s)
    {
        switch (s)
        {
            using enum Status;
        case Unknown: /*...*/
            break;
        case Created: /*...*/
            break;
        case Connected: /*...*/
            break;
        }
    }

    std::string_view to_string(Status const s)
    {
        switch (s)
        {
            using enum Status;
        case Unknown:
            return "Unknown";
        case Created:
            return "Created";
        case Connected:
            return "Connected";
        }
    }
#endif

    void execute()
    {
        Codes code = Codes::Unknown;
        Codes c1 = Codes::OK; // OK
        // int c2 = Codes::Failure;                // error (enum class에서 암시적 변환되지 않음)
        int c3 = static_cast<int>(Codes::Failure); // OK(명시적 변환)
        {
#ifdef HAS_USING_ENUMS
            using Status::Unknown;
            Status s = Unknown;
            foo::Status s = foo::Created; // instead of foo::Status::Created
#endif
        }
    }
}