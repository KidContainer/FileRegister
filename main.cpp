#include "Clean.h"

int main() {

	Clean cleaner;
	auto currentPath = fs::current_path();
	cleaner.coreWork(currentPath);

	return 0;
}
