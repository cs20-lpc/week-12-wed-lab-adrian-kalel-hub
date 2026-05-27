template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    for (int i = 0; i < this->M; i++)
    {
        int index = probeIndex(key, i);

        // empty slot found, insert key
        if (!this->occupied[index])
        {
            this->table[index] = key;
            this->occupied[index] = true;
            this->N++;
            return i + 1; // probes taken
        }

        // key already exists, do not insert
        if (this->occupied[index] &&
            this->table[index] == key)
        {
            return i + 1; // probes taken
        }
    }

    return -1; // table full

}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    for (int i = 0; i < this->M; i++)
    {
        int index = probeIndex(key, i);

        // empty slot found, key not present
        if (!this->occupied[index])
        {
            return {false, i + 1}; // not found, probes taken
        }

        // key found
        if (this->occupied[index] &&
            this->table[index] == key)
        {
            return {true, i + 1}; // found, probes taken
        }
    }
    return {false, -1}; // not found, probes taken
    //vsc ai suggestion
}
