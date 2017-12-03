#ifndef WORDINGENGINE_WORDINGENGINE_HPP
#define WORDINGENGINE_WORDINGENGINE_HPP

#include <string>
#include <unordered_map>
#include <bits/unordered_map.h>
#include <iostream>

namespace wordingEngine{

    int getNextMarkerIndex(std::string input, size_t startIndex, std::string markerToFind){

        for(size_t i = startIndex; i < input.size(); i++){
            bool found = true;

            for(size_t m = 0; m < markerToFind.size(); m++){
                if(i+m >= input.size())
                    return -1; // -1 signals eof

                if(input.at(i + m) != markerToFind.at(m)){
                    found = false;
                }
            }
            if(found){
                return i;
            }
        }

    }

    std::string process(std::string input, std::unordered_map<std::string, std::string> map, std::string startMarker = "{{", std::string endMarker = "}}"){
        bool eof = false;
        int index = 0;

        while(index != -1){
            index = getNextMarkerIndex(input, index, startMarker);

            if(index != -1){ // Marker has been found
                std::string variableToResolve = "";
                int endIndex = getNextMarkerIndex(input, index, endMarker);
                if(endIndex != -1){ // EndMarker has been found
                    variableToResolve = input.substr(index + startMarker.size(), (endIndex - index) - endMarker.size());

                    std::string newValue = map.at(variableToResolve);
                    input.replace(index + startMarker.size(), (endIndex - index) - endMarker.size(), newValue);


                }else{
                    std::cout << "error" << std::endl;
                }

                index += (endIndex - index) - endMarker.size();

            }

        }

        return input;
    }
}

#endif //WORDINGENGINE_WORDINGENGINE_HPP
