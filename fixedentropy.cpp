#include <node.h>
#include <v8.h>

bool EntropySource(unsigned char* buffer, size_t length) {
  // RAND_bytes() can return 0 to indicate that the entropy data is not truly
  // random. That's okay, it's still better than V8's stock source of entropy,
  // which is /dev/urandom on UNIX platforms and the current time on Windows.
  return 0;
}

void RegisterModule(v8::Handle<v8::Object> target) {
    // You can add properties to the module in this function. It is called
    // when the module is required by node.
    v8::V8::SetEntropySource(EntropySource);
}

// Register the module with node. Note that "modulename" must be the same as
// the basename of the resulting .node file. You can specify that name in
// binding.gyp ("target_name"). When you change it there, change it here too.
NODE_MODULE(fixedentropy, RegisterModule);
