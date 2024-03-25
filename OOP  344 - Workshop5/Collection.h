/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Feb 17,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include<string>

namespace seneca {
	template <typename T>
	class Collection {
		std::string m_name;
		T* items;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&);

	public:
		Collection(const std::string& name) :m_name(name), items(nullptr), m_size(0), m_observer(nullptr) {};
		
		~Collection(){
		  delete[] items;
		}

		Collection(const Collection& I) = delete;

		Collection(Collection&& I) = delete;

		Collection& operator=(const Collection& other) = delete;

		Collection& operator=(Collection&& other) = delete;

		const std::string& name() const { return m_name; }

		size_t size() const { return m_size; }

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		};

		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < m_size; ++i) {
				if (items[i].title() == item.title()) return *this;
			}

			T* newItems = new T[m_size + 1];
			for (size_t i = 0; i < m_size; ++i) {
				newItems[i] = items[i];
			}
			newItems[m_size] = item;
			delete[] items;
			items = newItems;
			++m_size;
			if (m_observer != nullptr) m_observer(*this, item);
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= m_size) {
				throw std::out_of_range(std::string("Bad index [") + std::to_string(idx) + std::string("]. Collection has [") + std::to_string(m_size) + std::string("] items."));
			}
			else {
				return items[idx];
			}
		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; ++i) {
				if (items[i].title() == title) {
					return &items[i];
				}
			}
			return nullptr; 
		}

	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			os << collection[i];
		}
		return os;
	}

}


#endif