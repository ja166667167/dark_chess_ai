#ifndef SCORE_H
#define SCORE_H

#include <ostream>

class Score
{
	public:
		/** Default constructor */
		Score();
		/** Default destructor */
		virtual ~Score();
		/** Copy constructor
		 *  \param other Object to copy from
		 */
		Score(const Score& other);
		/** Assignment operator
		 *  \param other Object to assign from
		 *  \return A reference to this
		 */
		friend std::ostream & operator<<(std::ostream &, const Score &);
		
		Score& operator=(const Score& other);

		bool operator<(const Score&) const;

		bool maxScore();
		bool minScore();

		Score& operator-();

//    protected:

//    private:
		double rateWin;
		float myWays;
		double rateDraw;
		float opWays;
		double rateLose;
};

#endif // SCORE_H
