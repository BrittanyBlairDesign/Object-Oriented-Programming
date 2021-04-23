#pragma once
class Vector3;
/////////////////////////////////////////////////////////////////////////////////////
// A sandbox for playing with Vector3 objects.
/////////////////////////////////////////////////////////////////////////////////////
template<size_t kMaxDataCount>
class Vector3Playground
{
private:
	Vector3 m_data[kMaxDataCount];
	size_t m_dataCount;

public:
	Vector3Playground()
		: m_data{}
		, m_dataCount{ 0 }

	{
	}

	/////////////////////////////////////////////////////////////////////////////////////
	// Adds a Vector3 to the data set.
	// RETURNS: true if the operation succeeds, false if kMaxDataCount has been reached.
	/////////////////////////////////////////////////////////////////////////////////////
	bool AddData(const Vector3& data)
	{
		if (m_dataCount >= kMaxDataCount)
			return false;

		m_data[m_dataCount] = data;
		++m_dataCount;
		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	// RETURNS: the number of stored vectors.
	/////////////////////////////////////////////////////////////////////////////////////
	size_t GetDataCount() const { return m_dataCount; }

	/////////////////////////////////////////////////////////////////////////////////////
	// RETURNS: a pointer to one vector in the set, or nullptr if index is out of range.
	/////////////////////////////////////////////////////////////////////////////////////
	const Vector3* GetData(size_t index) const
	{
		if (index >= m_dataCount)
			return nullptr;

		return &m_data[index];
	}

	/////////////////////////////////////////////////////////////////////////////////////
	// Assigns a new value to data at the specified index.
	// RETURNS: true if the operation succeeds, false if index is out of range.
	/////////////////////////////////////////////////////////////////////////////////////
	bool ModifyData(size_t index, const Vector3& newValue)
	{
		if (index >= m_dataCount)
			return false;

		m_data[index] = newValue;
		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	// Removes a vector from the data set.
	// RETURNS: true if the operation succeeds, false if index is out of range.
	/////////////////////////////////////////////////////////////////////////////////////
	bool RemoveData(size_t index)
	{
		if (index >= m_dataCount)
			return false;

		for (size_t i = index; i < m_dataCount - 1; ++i)
		{
			m_data[i] = m_data[i + 1];
		}

		--m_dataCount;
		return true;
	}
};