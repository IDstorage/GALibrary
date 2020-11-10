namespace galib {

    template <class _Typ>
    class UqPtr {
        _Typ* raw_data = nullptr;

    public:
        // FIXME: Add Move Semantic
        explicit UqPtr(_Typ&& data) : raw_data(new _Typ(data)) {}
        
    private:
        UqPtr(UqPtr<_Typ>&& cpy) {}

    public:
        _Typ* Data() const { return raw_data; }

    public:
        _Typ* operator->() const { return raw_data; }

        _Typ& operator*() const { return *raw_data; }
    };

}