#include<experimental\filesystem>
#include<string>

int main() {

	auto currentPath = std::experimental::filesystem::current_path();
	for (auto &Path : std::experimental::filesystem::recursive_directory_iterator(currentPath)) {
		std::string pathName = Path.path().string();
		if (pathName.find("登记簿.txt") != std::string::npos)
			std::experimental::filesystem::remove(Path.path());
	}

	return 0;
}
