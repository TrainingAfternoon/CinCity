///
/// Created by Sam Keyser on 4/30/2021
//

/**
 * Splits a given string along the given delimiter pattern. It is destructive towards the split character(s)
 * Pre: The String should be non null
 * @param str the string to split
 * @param delim a regular expression describing the pattern to split str along
 * @return a vector containing the chunks of the string
 */
vector<string> split(const string& str, const string& delim) {
    vector<string> output;
    regex splitter(delim);
    bool limited = limit > 0;
    //TODO: add a limit opt param
    sregex_token_iterator it(str.begin(), str.end(), -1, delim);
    for(sregex_token_iterator end; it != end; ++it) {
        output.pushback(it->str());
    }
    return output;
}
