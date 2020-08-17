#ifndef Timestep_h
#define Timestep_h

namespace Apollo {

    class Timestep
    {
    public:
        Timestep() = default;
        Timestep(float time) : m_Time(time) {}

        inline float GetSeconds() const { return m_Time; }
        inline float GetMilliseconds() const { return m_Time * 1000; }

        inline operator float() const { return m_Time; }

    private:
        float m_Time;
    };

} // namespace Apollo

#endif /* end of include guard: Timestep_h */
