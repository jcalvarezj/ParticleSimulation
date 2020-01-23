/*
 * Header file definition
 *
 * @author J. Alvarez
 */

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace ParticleSimulation {

struct Particle {
virtual void update() = 0;
virtual double getFirstCoordinate() = 0;
virtual double getSecondCoordinate() = 0;
virtual void toString() = 0;
};

} // namespace ParticleSimulation

#endif // PARTICLE_HPP

