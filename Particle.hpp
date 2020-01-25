/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace ParticleSimulation {

/**
 * This Struct represents Particles in general: particles with rectangular or
 * polar coordinates. For rectangular coordinates, coord1 and 2 are x and y
 * respectively; for polar coodinates, r and theta. However, for polar 
 * coordinates, coord1Speed will be used for other purposes such as rotational
 * speed
 */
struct Particle {
	enum Mode {RECT_RECT, RECT_CIRC, RECT_IMPD, POLR_FLWR, POLR_SPRL};

	int m_mode;
	double m_coord1;
	double m_coord2;
	double m_coord1Speed;
	double m_coord2Speed;

	/**
	 * Generic constructor to instantiate Particle types and intialize their
	 * fields
	 */
	Particle(double coord1, double coord2, double coord1Speed,
			double coord2Speed, int mode): m_coord1(coord1), m_coord2(coord2),
			m_coord1Speed(coord1Speed), m_coord2Speed(coord2Speed), m_mode(mode)
	{}

	/**
	 * Updates the Particle's position according to type-specific logic. Uses
	 * the interval parameter to calculate speeds
	 * @param interval Difference between current Screen time rendering and
	 *                 previous one
	 */
	virtual void update(int interval) = 0;
};

} // namespace ParticleSimulation

#endif // PARTICLE_HPP

