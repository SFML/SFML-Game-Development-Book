#ifndef BOOK_AIRCRAFT_HPP
#define BOOK_AIRCRAFT_HPP

#include <Book/Entity.hpp>
#include <Book/Command.hpp>
#include <Book/ResourceIdentifiers.hpp>
#include <Book/Projectile.hpp>
#include <Book/TextNode.hpp>
#include <Book/Animation.hpp>

#include <SFML/Graphics/Sprite.hpp>


class Aircraft : public Entity
{
	public:
		enum Type
		{
			Eagle,
			Raptor,
			Avenger,
			TypeCount
		};


	public:
								Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);

		virtual unsigned int	getCategory() const;
		virtual sf::FloatRect	getBoundingRect() const;
		virtual void			remove();
		virtual bool 			isMarkedForRemoval() const;
		bool					isAllied() const;
		float					getMaxSpeed() const;
		void					disablePickups();

		void					increaseFireRate();
		void					increaseSpread();
		void					collectMissiles(unsigned int count);

		void 					fire();
		void					launchMissile();
		void					playLocalSound(CommandQueue& commands, SoundEffect::ID effect);
		int						getIdentifier();
		void					setIdentifier(int identifier);
		int						getMissileAmmo() const;
		void					setMissileAmmo(int ammo);


	private:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
		void					updateMovementPattern(sf::Time dt);
		void					checkPickupDrop(CommandQueue& commands);
		void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);

		void					createBullets(SceneNode& node, const TextureHolder& textures) const;
		void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
		void					createPickup(SceneNode& node, const TextureHolder& textures) const;

		void					updateTexts();
		void					updateRollAnimation();


	private:
		Type					mType;
		sf::Sprite				mSprite;
		Animation				mExplosion;
		Command 				mFireCommand;
		Command					mMissileCommand;
		sf::Time				mFireCountdown;
		bool 					mIsFiring;
		bool					mIsLaunchingMissile;
		bool 					mShowExplosion;
		bool					mExplosionBegan;
		bool					mSpawnedPickup;
		bool					mPickupsEnabled;

		int						mFireRateLevel;
		int						mSpreadLevel;
		int						mMissileAmmo;

		Command 				mDropPickupCommand;
		float					mTravelledDistance;
		std::size_t				mDirectionIndex;
		TextNode*				mHealthDisplay;
		TextNode*				mMissileDisplay;
	
		int						mIdentifier;};

#endif // BOOK_AIRCRAFT_HPP
