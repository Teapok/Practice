#pragma once
#include <string>
#include <iostream>
#include <string>

namespace cf {

	class Object {
	protected:
		size_t capacity;
		size_t attendance;
		int m_maxCapacity;
	public:
		Object() {
			capacity = 0;
			attendance = 0;
			m_maxCapacity = 0;
		}
		Object(int maxCapacity) : m_maxCapacity(maxCapacity) {
			capacity = 0;
			attendance = 0;
		}
		virtual void setCapacity(size_t c) {
			if (c <= m_maxCapacity)
				capacity = c;
		}
		virtual size_t getCapacity() {
			return capacity;
		}
		virtual void setAttendance(size_t a) {
			attendance = a;
		}
		virtual size_t getAttendance() {
			return attendance;
		}
		virtual void setMaxCapacity(size_t c) {
			m_maxCapacity = c;
		}
		virtual size_t getMaxCapacity() {
			return m_maxCapacity;
		}
		virtual ~Object() {}
	};

	class Sector : Object {
	private:
		int m_id;
	public:
		Sector(int id = 0, size_t maxCapacity = 0) : Object(maxCapacity), m_id(id) {}
		void setID(int id) {
			m_id = id;
		}
		int getID() const {
			return m_id;
		}
	};

	class Stadium : Object {
	private:
		std::string m_name;
		std::string m_footballClub;
		std::string m_address;
		Sector * sectors;
		size_t m_countSectors;
	public:
		Stadium() : Object() {
			sectors = 0;
			m_countSectors = 0;
		}
		Stadium(std::string name, size_t countSectors, size_t maxCapacity,
			std::string footballClub, std::string address) :
			Object(maxCapacity), m_name(name), m_countSectors(countSectors),
			m_footballClub(footballClub), m_address(address) {
			sectors = new Sector[countSectors];
			/*
			set the value of the sectors
			id, maxCapacity = maxCapacity / countSectors;
			*/
		}
		void setName(std::string & name) {
			m_name = name;
		}
		void setFootballClub(std::string & footballClub) {
			m_footballClub = footballClub;
		}
		void setAddress(std::string & address) {
			m_address = address;
		}
		const std::string & getName() const {
			return m_name;
		}
		const std::string & getFootballClub() const {
			return m_footballClub;
		}
		const std::string & getAddress() const {
			std::cout << m_address;
			return m_address;
		}
		virtual ~Stadium() {
			/*
			free memory
			*/
		}
	};
}

