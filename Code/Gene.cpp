namespace galib {

    template <class _Typ>
    class Gene {
    private:
        _Typ element;
    public:
        Gene(_Typ data) : element(data) {}
        ~Gene() {
            
        }

    public:
        static Gene* Create(_Typ data) {
            Gene* _g = new Gene(data);
            return _g;
        }
    };

}