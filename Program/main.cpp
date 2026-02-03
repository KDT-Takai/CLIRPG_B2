#include"System/GameManager/GameManager.hpp"

int main()
{
	System::GameManager::Create();
	System::GameManager* GameManager = System::GameManager::GetInstance();
	GameManager->Initilaize();
	GameManager->Run();
	GameManager->Finalize();
	return 0;
}