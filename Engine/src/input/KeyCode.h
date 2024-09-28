#ifndef TOWELL_KEYCODE_H
#define TOWELL_KEYCODE_H

namespace Towell::Input
{
    /**
    * @brief Keyboard Input Codes
    * 
    * The codes in this enum follow the standards defined by the USB specification (usb.org)
    * according to the page "Keyboard/Keypad Page" (0x07) of the document available at
    * https://www.usb.org/sites/default/files/hut1_5.pdf
    */
	enum class KeyCode {
        // Letters
        A = 0x04,   // 'a' and 'A'
        B = 0x05,   // 'b' and 'B'
        C = 0x06,   // 'c' and 'C'
        D = 0x07,   // 'd' and 'D'
        E = 0x08,   // 'e' and 'E'
        F = 0x09,   // 'f' and 'F'
        G = 0x0A,   // 'g' and 'G' 
        H = 0x0B,   // 'h' and 'H' 
        I = 0x0C,   // 'i' and 'I' 
        J = 0x0D,   // 'j' and 'J' 
        K = 0x0E,   // 'k' and 'K' 
        L = 0x0F,   // 'l' and 'L'  
        M = 0x10,   // 'm' and 'M' 
        N = 0x11,   // 'n' and 'N' 
        O = 0x12,   // 'o' and 'O' 
        P = 0x13,   // 'p' and 'P' 
        Q = 0x14,   // 'q' and 'Q' 
        R = 0x15,   // 'r' and 'R'  
        S = 0x16,   // 's' and 'S' 
        T = 0x17,   // 't' and 'T' 
        U = 0x18,   // 'u' and 'U'  
        V = 0x19,   // 'v' and 'V'  
        W = 0x1A,   // 'w' and 'W' 
        X = 0x1B,   // 'x' and 'X'  
        Y = 0x1C,   // 'y' and 'Y' 
        Z = 0x1D,   // 'z' and 'Z'  
        
        // Digits
        Key1 = 0x1E,    // '1' and '!'
        Key2 = 0x1F,    // '2' and '@'
        Key3 = 0x20,    // '3' and '#'
        Key4 = 0x21,    // '4' and '$'
        Key5 = 0x22,    // '5' and '%'
        Key6 = 0x23,    // '6' and '^'
        Key7 = 0x24,    // '7' and '&'
        Key8 = 0x25,    // '8' and '*'
        Key9 = 0x26,    // '9' and '('
        Key0 = 0x27,    // '0' and ')'

        // Control keys
        Enter = 0x28,       // Return (ENTER)
        Escape = 0x29,      // Escape
        Backspace = 0x2A,   // Delete (Backspace)
        Tab = 0x2B,         // Tab
        Space = 0x2C,       // Spacebar
        Minus = 0x2D,       // '-' and (underscore)
        Equals = 0x2E,      // '=' and '+'
        LeftBracket = 0x2F, // '[' and '{'    
        RightBracket = 0x30,// ']' and '}'        
        Backslash = 0x31,   // '\' and '|'    
        NonUSHash = 0x32,   // Non-US '#' and '˜'
        SemiColon = 0x33,   // ';' and ':'    
        Apostrophe = 0x34,  // ''' and '"'    
        Grave = 0x35,       // '´' and '~'
        Comma = 0x36,       // ',' and '<'
        Period = 0x37,      // '.' and '>'
        Slash = 0x38,       // '/' and '?'
        CapsLock = 0x39,    // Caps Lock    

        // Function keys
        F1 = 0x3A, 
        F2 = 0x3B, 
        F3 = 0x3C, 
        F4 = 0x3D, 
        F5 = 0x3E, 
        F6 = 0x3F, 
        F7 = 0x40, 
        F8 = 0x41, 
        F9 = 0x42, 
        F10 = 0x43,
        F11 = 0x44,
        F12 = 0x45,
        PrintScreen = 0x46,
        ScrollLock = 0x47, 
        Pause = 0x48,      
        Insert = 0x49,     
        Home = 0x4A,       
        PageUp = 0x4B,     
        Delete = 0x4C,     
        End = 0x4D,        
        PageDown = 0x4E,   
        RightArrow = 0x4F, 
        LeftArrow = 0x50,  
        DownArrow = 0x51,  
        UpArrow = 0x52,    
        NumLock = 0x53,     // Num Lock and Clear

        // Keypad keys
        KeypadDivide = 0x54,    // Keypad '/'
        KeypadMultiply = 0x55,  // Keypad '*'
        KeypadMinus = 0x56,     // Keypad '-'
        KeypadPlus = 0x57,      // Keypad '+'
        KeypadEnter = 0x58,     // Keypad ENTER
        Keypad1 = 0x59,         // Keypad 1 and End
        Keypad2 = 0x5A,         // Keypad 2 and Down Arrow
        Keypad3 = 0x5B,         // Keypad 3 and PageDn
        Keypad4 = 0x5C,         // Keypad 4 and Left Arrow
        Keypad5 = 0x5D,         // Keypad 5
        Keypad6 = 0x5E,         // Keypad 6 and Right Arrow
        Keypad7 = 0x5F,         // Keypad 7 and Home
        Keypad8 = 0x60,         // Keypad 8 and Up Arrow
        Keypad9 = 0x61,         // Keypad 9 and PageUp
        Keypad0 = 0x62,         // Keypad 0 and Insert
        KeypadPeriod = 0x63,    // Keypad '.' and Delete
        
        NonUSBackslash = 0x64,  // Non-US '\' and '|'
        Application = 0x65,
        Power = 0x66,
       
        KeypadEquals = 0x67,    // Keypad =

        // Extra Function keys
        F13 = 0x68,
        F14 = 0x69,
        F15 = 0x6A,
        F16 = 0x6B,
        F17 = 0x6C,
        F18 = 0x6D,
        F19 = 0x6E,
        F20 = 0x6F,
        F21 = 0x70,
        F22 = 0x71,
        F23 = 0x72,
        F24 = 0x73,

        // Other
        Execute = 0x74,
        Help = 0x75,
        Menu = 0x76,
        Select = 0x77,
        Stop = 0x78,
        Again = 0x79,
        Undo = 0x7A,
        Cut = 0x7B,
        Copy = 0x7C,
        Paste = 0x7D,
        Find = 0x7E,
        Mute = 0x7F,
        VolumeUp = 0x80,
        VolumeDown = 0x81,
        LockingCapsLock = 0x82,
        LockingNumLock = 0x83,
        LockingScrollLock = 0x84,
        KeypadComma = 0x85,
        EqualSign = 0x86,
        International1 = 0x87,
        International2 = 0x88,
        International3 = 0x89,
        International4 = 0x8A,
        International5 = 0x8B,
        International6 = 0x8C,
        International7 = 0x8D,
        International8 = 0x8E,
        International9 = 0x8F,
        LANG1 = 0x90,
        LANG2 = 0x91,
        LANG3 = 0x92,
        LANG4 = 0x93,
        LANG5 = 0x94,
        LANG6 = 0x95,
        LANG7 = 0x96,
        LANG8 = 0x97,
        LANG9 = 0x98,
        AlternateErase = 0x99,
        SysReq = 0x9A,          // SysReq/Attention
        Cancel = 0x9B,
        Clear = 0x9C,
        Prior = 0x9D,
        Return = 0x9E,
        Separator = 0x9F,
        Out = 0xA0,
        Oper = 0xA1,
        ClearAgain = 0xA2,      // Clear/Again
        CrSel = 0xA3,           // CrSel/Props
        ExSel = 0xA4,
        
        Keypad00 = 0xB0,                // Keypad 00
        Keypad000 = 0xB1,               // Keypad 000
        ThousandsSeprator = 0xB2,
        DecimalSeparator = 0xB3,
        CurrencyUnit = 0xB4,
        CurrencySubUnit = 0xB5,
        KeyPadLeftParanthesis = 0xB6,   // Keypad (
        KeyPadRightParanthesis = 0xB7,  // Keypad )
        KeyPadLeftBrace = 0xB8,         // Keypad {
        KeyPadRightBrace = 0xB9,        // Keypad }
        KeypadTab = 0xBA,
        KeypadBackspace = 0xBB,
        KeypadA = 0xBC,
        KeypadB = 0xBD,
        KeypadC = 0xBE,
        KeypadD = 0xBF,
        KeypadE = 0xC0,
        KeypadF = 0xC1,
        KeypadXOR = 0xC2,
        KeypadPower = 0xC3,             // Keypad ^
        KeypadPercent = 0xC4,           // Keypad %
        KeypadLess = 0xC5,              // Keypad <
        KeypadGreater = 0xC6,           // Keypad >
        KeypadAmpersand = 0xC7,         // Keypad &
        KeypadDoubleAmpersand = 0xC8,   // Keypad &&
        KeypadVerticalBar = 0xC9,       // Keypad |
        KeypadDoubleVerticalBar = 0xCA, // Keypad ||
        KeypadColon = 0xCB,             // Keypad :
        KeypadHash = 0xCC,              // Keypad !
        KeypadSpace = 0xCD,
        KeypadAt = 0xCE,                // Keypad @
        KeypadExclamation = 0xCF,       // Keypad !
        KeypadMemoryStore = 0xD0,
        KeypadMemoryRecall = 0xD1,
        KeypadMemoryClear = 0xD2,
        KeypadMemoryAdd = 0xD3,
        KeypadMemorySubtract = 0xD4,
        KeypadMemoryMultiply = 0xD5,
        KeypadMemoryDivide = 0xD6,
        KeypadPlusMinus = 0xD7,         // Keypad +/-
        KeypadClear = 0xD8,
        KeypadClearEntry = 0xD9,
        KeypadBinary = 0xDA,
        KeypadOctal = 0xDB,
        KeypadDecimal = 0xDC,
        KeypadHexadecimal = 0xDD,
        
        // Modifier keys
        LeftControl = 0xE0,
        LeftShift = 0xE1,
        LeftAlt = 0xE2,
        LeftGUI = 0xE3,  // Windows/Command key
        RightControl = 0xE4,
        RightShift = 0xE5,
        RightAlt = 0xE6,
        RightGUI = 0xE7,
	};
}

#endif // TOWELL_KEYCODE_H

