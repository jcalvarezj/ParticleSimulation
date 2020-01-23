/*
 * Particle simulation program using the SDL library
 * Based on examples by John Purcell's (from Cave of Programming)
 *
 * @author J. Alvarez
 */
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace ParticleSimulation {

struct Particle {
	double m_x;
	double m_y;
	double m_xSpeed;
	double m_ySpeed;
	Particle();
	void update();
};

} // namespace ParticleSimulation

#endif // PARTICLE_HPP
