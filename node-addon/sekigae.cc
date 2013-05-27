#include <node.h>
#include <v8.h>

#include <string>
#include <vector>
#include <algorithm>

using namespace v8;
using namespace std;

Handle<Value> Method(const Arguments& args) {
    HandleScope scope;

    vector<Local<String> > freshers;
    freshers.push_back(String::New("おっくん"));
    freshers.push_back(String::New("ぐっさん"));
    freshers.push_back(String::New("たけお"));
    freshers.push_back(String::New("きたけー"));

    srand(static_cast<size_t>(time(NULL)));
    random_shuffle(freshers.begin(), freshers.end());

    Local<Array> array = Array::New(freshers.size());
    for (size_t i = 0; i < freshers.size(); i++) {
        array->Set(Int32::New(i), freshers[i]);
    }
    return scope.Close(array);
}

void Init(Handle<Object> exports, Handle<Object> module) {
    module->Set(String::NewSymbol("exports"),
                FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(sekigae, Init)
