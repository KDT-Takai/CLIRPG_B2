#pragma once

#include <memory>

#ifdef GENERATE_SINGLETON_BODY
#undef GENERATE_SINGLETON_BODY
#endif // GENERATE_SINGLETON_BODY

#define GENERATE_SINGLETON_BODY(Class)\
friend class Singleton<Class>;\
protected:\
Class()noexcept = default;\
virtual ~Class()noexcept = default;\
Class(const Class&) = delete;\
Class(Class&&) = delete;\
Class& operator=(const Class&) = delete;\
Class& operator=(Class&&) = delete;\

/// <summary>
/// Singleton pattern implementation with exception safety.
/// </summary>
template<typename T>
class Singleton
{
public:
	/// <summary>
	/// Creates the singleton instance if it doesn't exist yet.
	/// Uses make_unique for exception-safe construction.
	/// </summary>
	/// <returns>true: Instance created, false: Already exists</returns>
	static bool Create()
	{
		if (mInstance == nullptr)
		{
			mInstance = std::unique_ptr<T>(new T());
			mInstance->OnCreate();
			return true;
		}
		return false;
	}

	/// <summary>
	/// Releases the singleton instance.
	/// </summary>
	static void Release()
	{
		if (mInstance != nullptr)
		{
			mInstance->OnDestroy();
			mInstance.reset();  // Exception-safe cleanup
			mInstance = nullptr;
		}
	}

	/// <summary>
	/// Gets the singleton instance pointer.
	/// Returns nullptr if not yet created or already released.
	/// </summary>
	static T* GetInstance() noexcept
	{
		return mInstance.get();  // Use get() for unique_ptr access
	}

	/// <summary>
	/// Checks if the singleton instance exists.
	/// </summary>
	static bool HasInstance() noexcept
	{
		return mInstance != nullptr;
	}

protected:
	Singleton()noexcept = default;
	virtual ~Singleton()noexcept = default;

	virtual void OnCreate() {}
	virtual void OnDestroy() {}
private:
	static std::unique_ptr<T> mInstance;  // Exception-safe ownership
	
	// Disable copy/move constructors and assignment operators
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;

	// Allow unique_ptr to access destructor of T
	friend struct std::default_delete<T>;
};

// Static member definition (must be outside the class)
template<typename T>
std::unique_ptr<T> Singleton<T>::mInstance{ nullptr };
