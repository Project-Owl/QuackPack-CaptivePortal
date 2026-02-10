class QuackPack {
  public:
    QuackPack(){}

    virtual ~QuackPack() = default;
    template <typename DuckType>
    // virtual void init(DuckType& duck) = 0; //requires Duck<DuckWiFi>
    virtual void launch() {};
    virtual void execute() = 0;
    virtual const char* getName() const { return "uninitialized"; }
};
