using System.IO.Pipelines;

public class Twitter {
    private int time = 0;
    private Dictionary<int, HashSet<int>> follows;
    private Dictionary<int, List<(int tweetId, int time)>> tweets;

    public Twitter() {
        follows = new Dictionary<int, HashSet<int>>();
        tweets = new Dictionary<int, List<(int tweetId, int time)>>();
    }

    public void PostTweet(int userId, int tweetId) {
        if (!tweets.ContainsKey(userId))
            tweets[userId] = new List<(int, int)>();
        tweets[userId].Add((tweetId, time: ++time));
    }

    public IList<int> GetNewsFeed(int userId) {
        var pq = new SortedSet<(int tweetId, int time)>(
            Comparer<(int, int)>.Create((a, b) => {
                int cmp = b.Item2.CompareTo(a.Item2);
                return cmp;
            })
        );

        if (tweets.ContainsKey(userId)) {
            foreach (var t in tweets[userId])
                pq.Add(t);
        }

        if (follows.ContainsKey(userId)) {
            foreach (var f in follows[userId]) {
                if (tweets.ContainsKey(f)) {
                    foreach (var t in tweets[f])
                        pq.Add(t);
                }
            }
        }

        return pq.Take(10).Select(t => t.tweetId).ToList();
    }

    public void Follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (!follows.ContainsKey(followerId))
            follows[followerId] = new HashSet<int>();
        follows[followerId].Add(followeeId);
    }

    public void Unfollow(int followerId, int followeeId) {
        if (follows.ContainsKey(followerId))
            follows[followerId].Remove(followeeId);
    }
}


internal class Program
{
    public static void Main(string[] args)
    {
        Twitter twitter = new Twitter();
        twitter.PostTweet(1, 5); // User 1 posts a new tweet (id = 5).
        twitter.GetNewsFeed(1); // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
        twitter.Follow(1, 2); // User 1 follows user 2.
        twitter.PostTweet(2, 6); // User 2 posts a new tweet (id = 6).
        twitter.GetNewsFeed(1); // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
        twitter.Unfollow(1, 2); // User 1 unfollows user 2.
        twitter.GetNewsFeed(1); // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
    }
}