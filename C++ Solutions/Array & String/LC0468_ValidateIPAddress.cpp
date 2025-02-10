// 468. Validate IP Address
/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). 
For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and 
some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 
2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

class Solution {
public:
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    string validIPAddress(string IP) {
        if(IP.empty()) return "Neither";
        if(IP.back() == '.' || IP.back() == ':') return "Neither";
        string block;
        char token;
        if(IP.find(".") != string::npos){
            token = '.';
        } else if (IP.find(":") != string::npos) {
            token = ':';
        } else {
            return "Neither";
        }

        bool validBlock = true;
        int count = 0;
        stringstream ss(IP);
        while(getline(ss, block, token)){
            count++;
            validBlock = token == '.' ? isValidIPV4Part(block) : isValidIPV6Part(block);
            if (validBlock == false) {
                return "Neither";
            }
        }
        if (count == 4) {
            return "IPv4";
        } else if (count == 8) {
            return "IPv6";
        } else {
            return "Neither";
        }
    }
    
    //"A.a.aA.2", "A.a..2", '1.01.01.01', '1.1.1.1.'
    bool isValidIPV4Part(string block){
        if(block.size() > 0 && block.size() <= 3) {
            if(block.size() > 1 && block[0] == '0') return false;
            for(int i = 0; i < block.size(); i++){
                if(!isdigit(block[i])) return false;
            }
            int num = stoi(block);
            if(num >= 0 && num <  256){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    
    bool isValidIPV6Part(string block){
        if(block.size() == 0 || block.size() > 4) return false;

        for(int i = 0; i < block.size(); i++){
            if(!isalnum(block[i]) || validIPv6Chars.find(block[i]) == string::npos){
                return false;
            }
        }
        return true;
    }
};


// https://regex101.com/
// ^([0-9]{1,3}\.){3}[0-9]{1,3}(\/([0-9]|[1-2][0-9]|3[0-2]))?$
// '\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?(\.|$)){4}\b'